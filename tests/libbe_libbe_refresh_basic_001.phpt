--TEST--
Test libbe_refresh()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_init',
	'libbe_refresh',
	'libbe_close'
];
require('libbe_check.inc');
?>
--FILE--
<?php
// pretest
$be = libbe_init();

// test
libbe_refresh($be);
var_dump($be);

// posttest
libbe_close($be);
?>
===DONE===
--EXPECTF--
object(LibbeHandle)#%d (%d) {
}
===DONE===
