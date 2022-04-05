--TEST--
Test be_create_depth()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_init',
	'be_snapshot',
	'be_create_depth',
	'libbe_error_description',
	'be_destroy',
	'libbe_close'
];
require('libbe_check.inc');
?>
--FILE--
<?php
// pretest
$be = libbe_init();
$be_to_create = "libbe_ext_test".rand(0, 100);

// test
if ($be_from_snapshot = be_snapshot($be, be_active_name($be))) {
	var_dump(be_create_depth($be, $be_to_create, $be_from_snapshot));
	var_dump(libbe_error_description($be));
}

// posttest
be_destroy($be, $be_to_create);
libbe_close($be);
?>
===DONE===
--EXPECTF--
int(0)
string(8) "no error"
===DONE===
