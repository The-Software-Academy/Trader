TEMPLATE = subdirs

SUBDIRS = traderlib test

traderlib.subdir = traderlib
test.subdir = test


test.depends = traderlib

