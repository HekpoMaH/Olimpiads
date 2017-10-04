<?php
//Input
$n = 5;
$p = 3;
$a = array(1.0, 2.0, 3.0, 4.0, 5.0);

$groupunits = ceil($n / $p);

$i = 0;
while($i < $p) {
	$j = 0;
	while($j < $groupunits) {
		$s[$i] += $a[$i * $groupunits + $j];
		$j++;
	}
	
	if ($i == $p - 1) {
		$s[$i] /= ($n % $groupunits);
	}else{
		$s[$i] /= $groupunits;
	}
	
	$j = 0;
	while($j < $groupunits) {
		if (($i * $groupunits + $j) < count($a)) {
			$sa[$i] += pow($a[$i * $groupunits + $j] - $s[$i], 2);
		}
		$j++;
	}
	$i++;
}

//Output
echo array_sum($sa);
highlight_file(__FILE__);
?>