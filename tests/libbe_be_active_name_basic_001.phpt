--TEST--
Test be_active_name()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_init',
	'be_active_name',
	'libbe_close'
];
require('libbe_check.inc');
?>
--FILE--
<?php
// pretest
$be = libbe_init();

// test
var_dump(be_active_name($be));

// posttest
libbe_close($be);
?>
===DONE===
--EXPECTF--
string(%d) "%s"
===DONE===
