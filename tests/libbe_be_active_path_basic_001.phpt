--TEST--
Test be_active_path()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_init',
	'be_active_path',
	'libbe_close'
];
require('libbe_check.inc');
?>
--FILE--
<?php
// pretest
$be = libbe_init();

// test
var_dump(be_active_path($be));

// posttest
libbe_close($be);
?>
===DONE===
--EXPECTF--
string(%d) "%s"
===DONE===
