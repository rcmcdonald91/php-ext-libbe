--TEST--
Test be_create() with invalid name
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
$be_name = be_active_name($be).'libbeexttest&$.';
var_dump(be_create($be, $be_name));
var_dump(libbe_error_description($be));
be_destroy($be, $be_name);
libbe_close($be);
?>
===DONE===
--EXPECTF--
int(1)
string(29) "invalid boot environment name"
===DONE===
