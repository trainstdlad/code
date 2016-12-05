<?php
		$ip=$_SERVER['REMOTE_ADDR'];
		$ct=$_SERVER['DOCUMENT_ROOT'];
		$po=$_SERVER['SERVER_SOFTWARE'];
		$me=$_SERVER['REQUEST_METHOD'];
		$p=$_SERVER['SERVER_PROTOCOL'];
		$h=$_SERVER['HTTP_HOST'];
		$ad=$_SERVER['SERVER_ADMIN'];
		$ips=$_SERVER['SERVER_ADDR'];
		echo "Адрес удаленного компьютера: $ip <br/>";
		echo "Метод пересылки данных: $me <br/>";
		echo "Программное обеспечение сервера: $po <br/>";
		echo "Протокол передачи данных: $p <br/>";
		echo "Каталог для хранения документов на сервере: $ct <br/>";
		echo "IP-адрес сервера: $ips <br/>";
		echo "Почтовый адрес администратора сети: $ad <br/>";
		echo "Имя хост-компьютера: $h <br/>";
?>