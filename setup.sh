# In principle, you should be able to run this to setup everything you need to
# build the project. In practice, I haven't actually run this at all, so it's
# completely untested and here for informational purposes.

export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
mkdir -p $PREFIX/bin
export PATH="$PREFIX/bin:$PATH"

set TEMP=$(mktemp -d)
cd TEMP
set BINUTILS=binutils-2.24
wget http://ftp.gnu.org/gnu/binutils/$(echo $BINUTILS).tar.gz
tar -xf $BINUTILS
cd $BINUTILS
./configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install
