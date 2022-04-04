--TEST--
Test be_nextboot_name()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
if (!function_exists('be_nextboot_name'))
	print "skip";
?>
--FILE--
<?php
$be = libbe_init();
var_dump(be_nextboot_name($be));
libbe_close($be);
?>
===DONE===
--EXPECTF--
string(%d) "%s"
===DONE===
