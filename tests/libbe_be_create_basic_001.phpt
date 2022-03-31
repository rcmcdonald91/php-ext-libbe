--TEST--
Test be_create() with valid name
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--FILE--
<?php
$be = libbe_init();
$be_name = be_active_name($be).'libbeexttest';
var_dump(be_create($be, $be_name));
var_dump(libbe_error_description($be));
be_destroy($be, $be_name);
libbe_close($be);
?>
===DONE===
--EXPECTF--
int(0)
string(8) "no error"
===DONE===
