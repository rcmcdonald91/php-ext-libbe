--TEST--
Test libbe_close()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_check'
];
require('libbe_check.inc');
?>
--FILE--
<?php
// pretest

// test
var_dump(libbe_check());

// posttest
?>
===DONE===
--EXPECTF--
bool(true)
===DONE===
