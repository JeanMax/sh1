# SH1 #

fsh inside! (FlexShell)


### TODO: ###

* handle some more signals : ctrl-z (SIGTSTP, suspend)... stty -a for more infos
* memory leaks in cd, setenv, unsetenv, space_error... probably some more
* add to cd : cd [-p] [-l] [-n|-v]
"If name is not a subdirectory of the current directory (and does not begin with '/', './' or '../'), each component of the variable cdpath is checked to see if it has a subdirectory name. Finally, if all else fails but name is a shell variable whose value begins with '/', then this is tried to see if it is a directory.
With -p, prints the final directory stack, just like dirs. The -l, -n and -v flags have the same effect on cd as on dirs, and they imply -p. (+)"

Options for the cd tcsh built-in command are:
-l : Output is expanded explicitly to home or the path name of the home directory for the user.
-n : Entries are wrapped before they reach the edge of the screen.
-p : Prints the final directory stack.
-v : Entries are printed one per line, preceded by their stack positions.
If more than one of -n or -v is given, -v takes precedence. -p is accepted but does nothing.