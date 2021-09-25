#!/usr/bin/perl
print "Content-Type: text/html\r\n\r\n";
print "<HTML><BODY>\n";
($field_name, $username_to_look_for) = split(/=/, <>);
chomp $username_to_look_for;
$result = `last -1000 | grep $username_to_look_for`;
if ($result) {
print "$username_to_look_for has logged in recently.\n";
} else {
print "$username_to_look_for has NOT logged in recently.\n";
}
print "</BODY></HTML>\n";