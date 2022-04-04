--TEST--
Test libbe_init() with invalid root
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--FILE--
<?php
var_dump(libbe_init(" "));
?>
===DONE===
--EXPECTF--
Warning: libbe_init(): Could not initialize new libbe handle in %s on line %d
bool(false)
===DONE===
