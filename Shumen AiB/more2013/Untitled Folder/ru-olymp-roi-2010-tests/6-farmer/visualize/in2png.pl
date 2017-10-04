#!c:/soft/perl/perl.exe
use Image::Magick;

my $infile = shift @ARGV;
my $ansfile = shift @ARGV;

if (!defined($infile))
{
	print "Usage: in2png.pl <INFILE> [<ANSFILE>]\n";
	exit;
}

my $img = Image::Magick->new();

my $fh;
open($fh, "< ".$infile);
my $cline = <$fh>;
chomp;
my ($n, $m) = split(/ +/, $cline);
my ($i, $j);

my ($nn, $mm) = ($n, $m);
while ($nn < 200)
{
	$nn += $n;
	$mm += $m;
}
my $sz = $nn / $n;

$img->Set('size'=>$mm."x".$nn);
$img->ReadImage("xc:white");

for ($i = 0; $i < $n; $i++)
{
	$cline = <$fh>;
	chomp;
	my @cur = split(//, $cline);
	for ($j = 0; $j < $m; $j++)
	{
		if ($cur[$j] == 1) 
		{
			if ($sz == 1)
			{
				$img->Set("pixel[$j,$i]"=>'black');
			}
			else
			{
				$img->Draw('primitive'=>'rectangle',
				   'points'=>($j * $sz).",".($i * $sz).",".($j * $sz + $sz - 1).",".($i * $sz + $sz - 1),
				   'fill'=>'#000000');
			}
		}
	}
}
close($fh);

if (defined($ansfile))
{
	open($fh, "< ".$ansfile);
	$cline = <$fh>;
	my @crds = split(/ +/, $cline);
    $cline = <$fh>;
	my @crds2 = split(/ +/, $cline);
	$crds[0]--; $crds[1]--; $crds[2]--; $crds[3]--;
	$crds2[0]--; $crds2[1]--; $crds2[2]--; $crds2[3]--;
	$img->Draw('primitive'=>'rectangle',
			   'points'=>($crds2[1] * $sz).",".($crds2[0] * $sz).",".($crds2[3] * $sz + $sz - 1).",".($crds2[2] * $sz + $sz - 1),
			   'fill'=>'#FF00FF');
	$img->Draw('primitive'=>'rectangle',
			   'points'=>($crds[1] * $sz).",".($crds[0] * $sz).",".($crds[3] * $sz + $sz - 1).",".($crds[2] * $sz + $sz - 1),
			   'fill'=>'#00FF00');
}

binmode STDOUT;
print $img->Write("png:-");