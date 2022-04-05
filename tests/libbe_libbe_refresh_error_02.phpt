--TEST--
Test libbe_refresh() with invalid handle (string)
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_refresh'
];
require('libbe_check.inc');
?>
--FILE--
<?php
// pretest

// test
libbe_refresh("42");

// posttest
?>
===DONE===
--EXPECTF--
Warning: libbe_refresh() expects parameter %d to be LibbeHandle, %s given in %s on line %d
===DONE===
