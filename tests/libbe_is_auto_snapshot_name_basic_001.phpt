--TEST--
Test is_auto_snapshot_name_basic()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
$funcs = [
	'libbe_init',
	'be_is_auto_snapshot_name',
	'libbe_close'
];
require('libbe_check.inc');
?>
--FILE--
<?php
// pretest
$be = libbe_init();

// test
var_dump(be_is_auto_snapshot_name($be, 'default@2022-03-29-09:19:23-0'));
var_dump(be_is_auto_snapshot_name($be, 'mybe@notautosnapshotname'));
var_dump(be_is_auto_snapshot_name($be, 'defalult@an illegal name'));
var_dump(be_is_auto_snapshot_name($be, 'mybe@2022-03-29-09:19:23-0'));

// posttest
libbe_close($be);
?>
===DONE===
--EXPECTF--
bool(true)
bool(false)
bool(false)
bool(true)
===DONE===
