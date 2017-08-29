
TOPDIR = .

SUBDIRS = \
	lib \
	app \
	$(NULL)

include $(TOPDIR)/make/Makefile.inc

install-box:
	@if [ ! -x '/usr/local/bin/box' ]; then curl -sSL box-builder.sh | sudo bash; fi

docker-image: install-box
	box box.rb

docker-image-rebuild: install-box
	box -n box.rb
