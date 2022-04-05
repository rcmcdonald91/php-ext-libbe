--TEST--
Test be_rename()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_init',
	'be_create',
	'be_rename',
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
be_create($be, $be_to_create);
$be_name_new = $be_to_create.'_renamed';

// test
var_dump(be_rename($be, $be_to_create, $be_name_new));
var_dump(libbe_error_description($be));

// posttest
be_destroy($be, $be_to_create);
be_destroy($be, $be_name_new);
libbe_close($be);
?>
===DONE===
--EXPECTF--
int(0)
string(8) "no error"
===DONE===
