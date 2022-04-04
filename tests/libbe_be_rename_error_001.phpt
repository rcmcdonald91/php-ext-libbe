--TEST--
Test be_rename() with invalid name
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
if (!function_exists('be_rename'))
	print "skip";
?>
--FILE--
<?php
$be = libbe_init();
$be_to_create = "libbe_ext_test".rand(0, 100);
be_create($be, $be_to_create);
$be_name_new = $be_to_create.'&$.';
var_dump(be_rename($be, $be_to_create, $be_name_new));
var_dump(libbe_error_description($be));
be_destroy($be, $be_to_create);
be_destroy($be, $be_name_new);
libbe_close($be);
?>
===DONE===
--EXPECTF--
int(1)
string(29) "invalid boot environment name"
===DONE===
