<?php

$data = wordcompression_encode("dict.txt", file_get_contents("data.txt"));
$compressed = wordcompression_decode("dict.txt", $data);
printf("Compressed %f%%\n", (strlen($data) / strlen($compressed)) * 100);
