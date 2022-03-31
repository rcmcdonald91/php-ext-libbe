--TEST--
Test be_nicenum() with various numbers
--CREDITS--
R. Christian McDonald <cmcdonald@netgate.com>
--EXTENSIONS--
libbe
--FILE--
<?php
var_dump(be_nicenum(0));
var_dump(be_nicenum(1000));
var_dump(be_nicenum(10000));
var_dump(be_nicenum(1500000));
var_dump(be_nicenum(1500000000));
var_dump(be_nicenum(1500000000000));
var_dump(be_nicenum(150000000000000));
?>
===DONE===
--EXPECT--
string(1) "0"
string(4) "1000"
string(5) "9.77K"
string(5) "1.43M"
string(5) "1.40G"
string(5) "1.36T"
string(4) "136T"
===DONE===
