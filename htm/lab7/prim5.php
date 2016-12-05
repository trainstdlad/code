<?php
  $str=$_GET['text'];
  $s = str_word_count($str);
  echo "Количество слов в тексте: $s";
?>
