--TEST--
Test libbe_close() with invalid argument (int)
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_close'
];
require('libbe_check.inc');
?>
--FILE--
<?php
// pretest

// test
libbe_close(42);

// posttest
?>
===DONE===
--EXPECTF--
Warning: libbe_close() expects parameter 1 to be LibbeHandle, int given in %s on line %d
===DONE===
