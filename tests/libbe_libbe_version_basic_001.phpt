--TEST--
Test libbe_version()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
if (!function_exists('libbe_version'))
	print "skip";
?>
--FILE--
<?php
var_dump(libbe_version());
?>
===DONE===
--EXPECTF--
string(%d) "%d.%d.%d"
===DONE===
