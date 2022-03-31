--TEST--
Test libbee_close()
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--FILE--
<?php
$be = libbe_init();
libbe_close($be);
var_dump($be);
?>
===DONE===
--EXPECTF--
resource(%d) of type (Unknown)
===DONE===
