--TEST--
Test libbe_init()
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
$be = libbe_init();
var_dump($be);

// posttest
libbe_close($be);
?>
===DONE===
--EXPECTF--
object(LibbeHandle)#%d (%d) {
}
===DONE===
