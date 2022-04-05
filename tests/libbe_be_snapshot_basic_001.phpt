--TEST--
Test be_snapshot()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_init',
	'be_active_name',
	'be_snapshot',
	'be_is_auto_snapshot_name'
	'libbe_close'
];
require('libbe_check.inc');
?>
--FILE--
<?php
// pretest
$be = libbe_init();
$be_name = be_active_name($be);

// test
if ($ret = be_snapshot($be, $be_name)) {
	var_dump($ret);
	var_dump(be_is_auto_snapshot_name($be, $ret));
}

// posttest
libbe_close($be);
?>
===DONE===
--EXPECTF--
string(%d) "%s@%s"
bool(true)
===DONE===
