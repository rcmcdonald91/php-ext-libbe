--TEST--
Test be_rename() with valid name
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--FILE--
<?php
$be = libbe_init();
$be_name = be_active_name($be).'libbeexttest';
be_create($be, $be_name);
$be_name_new = $be_name.'renamed';
var_dump(be_rename($be, $be_name, $be_name_new));
var_dump(libbe_error_description($be));
be_destroy($be, $be_name);
be_destroy($be, $be_name_new);
libbe_close($be);
?>
===DONE===
--EXPECTF--
int(0)
string(8) "no error"
===DONE===
