--TEST--
Test libbe_init() with invalid root
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_init',
	'libbe_close'
];
require('libbe_check.inc');
?>
--FILE--
<?php
// pretest

// test
$be = libbe_init("SomeInvalidPath");
var_dump($be);

// posttest
libbe_close($be);
?>
===DONE===
--EXPECTF--
Warning: libbe_init(): Could not initialize LibbeHandle in %s on line %d
bool(false)

Warning: libbe_close() expects parameter %d to be LibbeHandle, bool given in %s on line %d
===DONE===
