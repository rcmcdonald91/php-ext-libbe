--TEST--
Test libbe_init()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--FILE--
<?php
$be = libbe_init();
var_dump($be);
libbe_close($be);
var_dump($be);
?>
===DONE===
--EXPECTF--
resource(%d) of type (libbe handle)
resource(%d) of type (Unknown)
===DONE===
