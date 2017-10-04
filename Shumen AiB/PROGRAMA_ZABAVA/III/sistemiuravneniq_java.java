
GaussianEliminationRectangular.java


Below is the syntax highlighted version of GaussianEliminationRectangular.java from §9.9 Scientific Computing.


/*************************************************************************
 *  Compilation:  javac GaussianEliminationRectangular.java
 *  Execution:    java GaussianEliminationRectangular M N
 * 
 *  Gaussian elimination with partial pivoting for M-by-N system.
 *
 *  % java GaussianEliminationRectangular M N
 *  -1.000000
 *  2.000000
 *  2.000000
 *
 *  3.000000
 *  -1.000000
 *  -2.000000
 * 
 *  System is infeasible
 *
 *  -6.250000
 *  -4.500000
 *  0.000000
 *  0.000000
 *  1.000000
 *
 *  System is infeasible
 *
 *  -1.375000
 *  1.625000
 *  0.000000
 *
 *************************************************************************/

public class GaussianEliminationRectangular {
    private static final double EPSILON = 1e-8;

    private final int M;      // number of rows
    private final int N;      // number of columns
    private double[][] a;     // M-by-N+1 augmented matrix

    // Gaussian elimination with partial pivoting
    public GaussianEliminationRectangular(double[][] A, double[] b) {
        M = A.length;
        N = A[0].length;

        if (b.length != M) throw new RuntimeException("Dimensions disagree");

        // build augmented matrix
        a = new double[M][N+1];
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                a[i][j] = A[i][j];
        for (int i = 0; i < M; i++) a[i][N] = b[i];

        forwardElimination();

        assert check(A, b);
    }

    // forward elimination
    private void forwardElimination() {
        for (int p = 0; p < Math.min(M, N); p++) {

            // find pivot row using partial pivoting
            int max = p;
            for (int i = p+1; i < M; i++) {
                if (Math.abs(a[i][p]) > Math.abs(a[max][p])) {
                    max = i;
                }
            }

            // swap
            swap(p, max);

            // singular or nearly singular
            if (Math.abs(a[p][p]) <= EPSILON) {
                continue;
                // throw new RuntimeException("Matrix is singular or nearly singular");
            }

            // pivot
            pivot(p);
        }
    }

    // swap row1 and row2
    private void swap(int row1, int row2) {
        double[] temp = a[row1];
        a[row1] = a[row2];
        a[row2] = temp;
    }

    // pivot on a[p][p]
    private void pivot(int p) {
        for (int i = p+1; i < M; i++) {
            double alpha = a[i][p] / a[p][p];
            for (int j = p; j <= N; j++) {
                a[i][j] -= alpha * a[p][j];
            }
        }
    }

    // back substitution
    public double[] primal() {
        double[] x = new double[N];
        for (int i = Math.min(N-1, M-1); i >= 0; i--) {
            double sum = 0.0;
            for (int j = i+1; j < N; j++) {
                sum += a[i][j] * x[j];
            }

            if (Math.abs(a[i][i]) > EPSILON)
                x[i] = (a[i][N] - sum) / a[i][i];
            else if (Math.abs(a[i][N] - sum) > EPSILON)
                return null;
        }

        // redundant rows
        for (int i = N; i < M; i++) {
            double sum = 0.0;
            for (int j = 0; j < N; j++) {
                sum += a[i][j] * x[j];
            }
            if (Math.abs(a[i][N] - sum) > EPSILON)
                return null;
        }
        return x;
    }

    // does the system have a solution?
    public boolean isFeasible() {
        return primal() != null;
    }


    // check that Ax = b
    private boolean check(double[][] A, double[] b) {
        if (!isFeasible()) return true;
        double[] x = primal();
        for (int i = 0; i < M; i++) {
            double sum = 0.0;
            for (int j = 0; j < N; j++) {
                sum += A[i][j] * x[j];
            }
            if (Math.abs(sum - b[i]) > EPSILON) {
                StdOut.println("not feasible");
                StdOut.println("b[" + i + "] = " + b[i] + ", sum = " + sum);
                return false;
            }
        }
        return true;
    }


    public static void test(String name, double[][] A, double[] b) {
        StdOut.println(name);
        GaussianEliminationRectangular gaussian = new GaussianEliminationRectangular(A, b);
        double[] x = gaussian.primal();
        if (gaussian.isFeasible()) {
            for (int i = 0; i < x.length; i++) {
                StdOut.printf("%.6f\n", x[i]);
            }
        }
        else {
            StdOut.println("System is infeasible");
        }
        StdOut.println();
    }


    // 3-by-3 nonsingular system
    public static void test1() {
        double[][] A = {
            { 0, 1,  1 },
            { 2, 4, -2 },
            { 0, 3, 15 }
        };
        double[] b = { 4, 2, 36 };
        test("test1", A, b);
    }

    // 3-by-3 nonsingular system
    public static void test2() {
        double[][] A = {
            {  1, -3,   1 },
            {  2, -8,   8 },
            { -6,  3, -15 }
        };
        double[] b = { 4, -2, 9 };
        test("test2", A, b);
    }

    // 5-by-5 singular: no solutions
    public static void test3() {
        double[][] A = {
            {  2, -3, -1,  2,  3 },
            {  4, -4, -1,  4, 11 },
            {  2, -5, -2,  2, -1 },
            {  0,  2,  1,  0,  4 },
            { -4,  6,  0,  0,  7 },
        };
        double[] b = { 4, 4, 9, -6, 5 };
        test("test3", A, b);
    }

    // 5-by-5 singular: infinitely many solutions
    public static void test4() {
        double[][] A = {
            {  2, -3, -1,  2,  3 },
            {  4, -4, -1,  4, 11 },
            {  2, -5, -2,  2, -1 },
            {  0,  2,  1,  0,  4 },
            { -4,  6,  0,  0,  7 },
        };
        double[] b = { 4, 4, 9, -5, 5 };
        test("test4", A, b);
    }

    // 3-by-3 singular: no solutions
    public static void test5() {
        double[][] A = {
            {  2, -1,  1 },
            {  3,  2, -4 },
            { -6,  3, -3 },
        };
        double[] b = { 1, 4, 2 };
        test("test5", A, b);
    }

    // 3-by-3 singular: infinitely many solutions
    public static void test6() {
        double[][] A = {
            {  1, -1,  2 },
            {  4,  4, -2 },
            { -2,  2, -4 },
        };
        double[] b = { -3, 1, 6 };
        test("test6", A, b);
    }

    // 4-by-3 full rank and feasible system
    public static void test7() {
        double[][] A = {
            { 0, 1,  1 },
            { 2, 4, -2 },
            { 0, 3, 15 },
            { 2, 8, 14 }
        };
        double[] b = { 4, 2, 36, 42 };
        test("test7", A, b);
    }

    // 4-by-3 full rank and infeasible system
    public static void test8() {
        double[][] A = {
            { 0, 1,  1 },
            { 2, 4, -2 },
            { 0, 3, 15 },
            { 2, 8, 14 }
        };
        double[] b = { 4, 2, 36, 40 };
        test("test8", A, b);
    }

    // 3-by-4 full rank system
    public static void test9() {
        double[][] A = {
            {  1, -3,   1,  1 },
            {  2, -8,   8,  2 },
            { -6,  3, -15,  3 }
        };
        double[] b = { 4, -2, 9 };
        test("test9", A, b);
    }

    // sample client
    public static void main(String[] args) {

        try                 { test1();             }
        catch (Exception e) { e.printStackTrace(); }
        StdOut.println("--------------------------------");

        try                 { test2();             }
        catch (Exception e) { e.printStackTrace(); }
        StdOut.println("--------------------------------");

        try                 { test3();             }
        catch (Exception e) { e.printStackTrace(); }
        StdOut.println("--------------------------------");

        try                 { test4();             }
        catch (Exception e) { e.printStackTrace(); }
        StdOut.println("--------------------------------");

        try                 { test5();             }
        catch (Exception e) { e.printStackTrace(); }
        StdOut.println("--------------------------------");

        try                 { test6();             }
        catch (Exception e) { e.printStackTrace(); }
        StdOut.println("--------------------------------");

        try                 { test7();             }
        catch (Exception e) { e.printStackTrace(); }
        StdOut.println("--------------------------------");

        try                 { test8();             }
        catch (Exception e) { e.printStackTrace(); }
        StdOut.println("--------------------------------");

        try                 { test9();             }
        catch (Exception e) { e.printStackTrace(); }
        StdOut.println("--------------------------------");

        // N-by-N random system
        int N = Integer.parseInt(args[0]);
        double[][]A = new double[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                A[i][j] = StdRandom.uniform(1000);
        double[] b = new double[N];
        for (int i = 0; i < N; i++)
            b[i] = StdRandom.uniform(1000);
        test(N + "-by-" + N, A, b);
    }

}


Copyright © 2002–2010, Robert Sedgewick and Kevin Wayne.
Last updated: Sat Aug 6 13:36:32 EDT 2011.
