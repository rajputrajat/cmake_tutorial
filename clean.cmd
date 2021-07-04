del /q .\out\build\*
FOR /D %%p IN (".\out\build\*.*") DO rmdir "%%p" /s /q
