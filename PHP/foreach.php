<?php
$arr=array(1,2,3,4,5,6);
foreach($arr as &$value)
{
	$value*=2;
	echo $value,"<br/>";
}for($i=0;$i<6;$i++)echo $arr[$i]," ";
echo "<br/>";
echo $arr[5]/2,"<br/>";
unset($value);
foreach($arr as $value)
{
	echo $value," ";
	$value/=2;
	echo $value,"<br/>";
}
for($i=0;$i<6;$i++)echo $arr[$i]," ";
echo "<br/>";
unset($value);
?>
