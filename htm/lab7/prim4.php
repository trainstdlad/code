<?php
	$snam=$_GET['surname'];
	$nam=$_GET['name'];
	$gro=$_GET['growth'];
	$wei=$_GET['weight'];
	$normal=$gro-100;
	if ($wei == $normal) {
		echo "$snam $nam вы имеете ";
	}
	elseif ($wei > $normal) {
		echo "$snam $nam у Вас избыточный вес, рекомендуем не сидеть за компьютером и жрать сладкое.<br>";
		echo "Нормальный вес $normal.<br>";
		$k=$wei-$normal;
		echo "Вам необходимо сбросить $k килограмм";
	}
	elseif ($wei < $normal){
		echo "$snam $nam у Вас недостаточная масса тела, рекомендуем больше есть в Маке.<br>";
		echo "Ваш нормальный вес $normal.<br>";
		$k=$normal-$wei;
		echo "Необходимо набрать $k килограмм";
	}
?>

