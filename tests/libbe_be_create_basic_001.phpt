--TEST--
Test be_create()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_init',
	'be_create',
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
var_dump(be_create($be, $be_to_create));
var_dump(libbe_error_description($be));

// posttest
be_destroy($be, $be_to_create);
libbe_close($be);
?>
===DONE===
--EXPECTF--
int(0)
string(8) "no error"
===DONE===
