<?php

foreach ($funcs as $func) {
	if (!function_exists($func)) {
		print 'skip';
		break;
	}
}
