import com.vividsolutions.jts.geom.*;
import com.vividsolutions.jts.geom.Point;
import com.vividsolutions.jts.geom.Polygon;
import com.vividsolutions.jts.geom.impl.CoordinateArraySequence;

import javax.imageio.ImageIO;
import javax.imageio.ImageWriter;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;
import java.util.Locale;

/**
 * User: Vitaly Goldshteyn
 * Date: 21.04.2010
 * Time: 9:34:24
 */

class Segment extends LineString
{
    Segment(Coordinate p1, Coordinate p2)
    {
        super(new CoordinateArraySequence(
                new Coordinate[]{p1, p2}),
                new GeometryFactory());
    }
}

class ApproximateSector
{
    public ApproximateSector(Coordinate center, double r,
                             Coordinate p1, Coordinate p2) {
        GeometryFactory factory = new GeometryFactory();
        Coordinate v = new Coordinate(p2.x - p1.x, p2.y - p1.y);
        Coordinate n = new Coordinate(v.y, -v.x);
        int MUL = 100000;
        LinearRing ring = factory.createLinearRing(new Coordinate[]{
                new Coordinate(p1.x - v.x * MUL, p1.y - v.y * MUL),
                new Coordinate(p2.x + v.x * MUL, p2.y + v.y * MUL),
                new Coordinate(p2.x + n.x * MUL, p2.y + n.y * MUL),
                new Coordinate(p1.x + n.x * MUL, p1.y + n.y * MUL),
                new Coordinate(p1.x - v.x * MUL, p1.y - v.y * MUL)
        });
        Polygon pol1 = factory.createPolygon(ring, null);
        int NMAX = 10000;
        r = r * Math.sqrt(2 * Math.PI / NMAX / Math.sin(2 * Math.PI / NMAX));
        Coordinate[] coords = new Coordinate[NMAX + 1];

        for(int i = 0; i < NMAX; ++i) {
            double alpha = 2 * Math.PI / NMAX * i;
            coords[i] = new Coordinate(center.x + r * Math.cos(alpha),
                                       center.y + r * Math.sin(alpha));     
        }
        coords[NMAX] = coords[0];
        Polygon pol2 = factory.createPolygon(factory.createLinearRing(coords), null);
        polygon = pol1.intersection(pol2);
    }

    public Geometry getGeometry() {
        return polygon;
    }

    private Geometry polygon;
}

public class DeerVisualisation {
    String imageOutput;
    public DeerVisualisation(String imageOutput) {
        this.imageOutput = imageOutput;
    }

    public static void main(String[] args) throws FileNotFoundException {
        DeerVisualisation impl = new DeerVisualisation(args.length == 1 ? args[0] : null);
        impl.read();
        impl.solve();
    }

    int n;
    Coordinate[] points;
    Coordinate start;
    int length;
    Geometry result;

    private void solve() {
        GeometryFactory factory = new GeometryFactory();
        int startEdge = -1;
        for(int i = 0; i < n; ++i) {
            Segment s = new Segment(points[i], points[i + 1]);
            if (s.intersects(factory.createPoint(start))) {
                startEdge = i;
                break;
            }
        }
        if (startEdge == -1) throw new IllegalStateException("point not on polygon");
        result = null;

        for(int dir = -1; dir <= 1; dir += 2) {
            double curLength = length;
            int curPos = (startEdge + (dir == 1 ? 1 : 0)) % n;
            Coordinate curCoord = start;
            int cnt = 0;

            while (curLength > 0.0 && cnt <= n) {
                Point curPoint =  factory.createPoint(curCoord);
                Point nextPoint = factory.createPoint(points[curPos]);
                Coordinate p1 = curCoord, p2 = points[curPos];
                if (dir == 1) {
                    Coordinate t = p1;
                    p1 = p2;
                    p2 = t;
                }
                ApproximateSector sector = new ApproximateSector(curCoord, curLength, p1, p2);

                if (result == null) {
                    result = sector.getGeometry();
                } else {
                    result = result.union(sector.getGeometry());
                }

                curLength -= curPoint.distance(nextPoint);

                curCoord = points[curPos];
                curPos = (curPos  + n + dir) % n;
                ++cnt;
            }
        }

        assert result != null;
        System.out.printf(Locale.US, "%.10f", result.getArea());

        visualate();
    }

    double minX, maxX, minY, maxY;

    int modifyCoordX(double x) {
        return (int)((x - minX) / Math.max((maxX- minX), (maxY- minY)) * 2000);
    }

    int modifyCoordY(double y) {
        return (int)((maxY - y) / Math.max((maxX- minX), (maxY- minY)) * 2000);
    }

    private void visualate() {
        if (imageOutput == null) {
            return ;
        }
        BufferedImage img = new BufferedImage(2000, 2000, BufferedImage.TYPE_INT_RGB);
        Graphics g = img.getGraphics();
        g.setColor(Color.WHITE);
        g.fillRect(0, 0, 4000, 4000);
        Coordinate[] coords = result.getCoordinates();

        minX = minY = 1e+9;
        maxX = maxY = -1e+9;
        for (Coordinate coord : coords) {
            minX = Math.min(minX, coord.x);
            maxX = Math.max(maxX, coord.x);
            minY = Math.min(minY, coord.y);
            maxY = Math.max(maxY, coord.y);
        }
        for (Coordinate coord : points) {
            minX = Math.min(minX, coord.x);
            maxX = Math.max(maxX, coord.x);
            minY = Math.min(minY, coord.y);
            maxY = Math.max(maxY, coord.y);
        }

        {
            int[] x = new int[points.length];
            int[] y = new int[points.length];
            for(int i = 0; i < points.length; ++i) {
                x[i] = modifyCoordX(points[i].x);
                y[i] = modifyCoordY(points[i].y);
            }
            g.setColor(Color.RED);
            g.fillPolygon(x, y, x.length);
        }
        {
            int[] x = new int[coords.length];
            int[] y = new int[coords.length];
            for(int i = 0; i < coords.length; ++i) {
                x[i] = modifyCoordX(coords[i].x);
                y[i] = modifyCoordY(coords[i].y);
            }
            g.setColor(Color.GREEN);
            g.fillPolygon(x, y, x.length);
        }
        {
            g.setColor(Color.BLUE);
            g.fillOval(modifyCoordX(start.x) - 7, modifyCoordY(start.y) - 7, 15, 15);
        }
        ImageWriter iw = ImageIO.getImageWritersByFormatName("png").next();
        try {
            iw.setOutput(ImageIO.createImageOutputStream(new File(imageOutput + ".png")));
            iw.write(img);
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private void read() throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        points = new Coordinate[n + 1];
        for(int i = 0; i < n; ++i) {
            points[i] = new Coordinate(in.nextInt(), in.nextInt());
        }
        points[n] = points[0];
        start = new Coordinate(in.nextInt(), in.nextInt());
        length = in.nextInt();
    }

}
