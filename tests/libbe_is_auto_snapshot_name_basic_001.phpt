--TEST--
Test is_auto_snapshot_name_basic()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--SKIPIF--
<?php
if (!function_exists('be_is_auto_snapshot_name'))
	print "skip";
?>
--FILE--
<?php
$be = libbe_init();
var_dump(be_is_auto_snapshot_name($be, 'default@2022-03-29-09:19:23-0'));
var_dump(be_is_auto_snapshot_name($be, 'mybe@notautosnapshotname'));
var_dump(be_is_auto_snapshot_name($be, 'defalult@an illegal name'));
var_dump(be_is_auto_snapshot_name($be, 'mybe@2022-03-29-09:19:23-0'));
libbe_close($be);
?>
===DONE===
--EXPECTF--
bool(true)
bool(false)
bool(false)
bool(true)
===DONE===
