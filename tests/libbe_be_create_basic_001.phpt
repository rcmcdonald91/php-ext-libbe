--TEST--
Test be_create() with valid name
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
if (!function_exists('be_create'))
	print "skip";
?>
--FILE--
<?php
$be = libbe_init();
$be_to_create = "libbe_ext_test".rand(0, 100);
var_dump(be_create($be, $be_to_create));
var_dump(libbe_error_description($be));
be_destroy($be, $be_to_create);
libbe_close($be);
?>
===DONE===
--EXPECTF--
int(0)
string(8) "no error"
===DONE===
