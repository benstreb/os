# In principle, you should be able to run this to setup everything you need to
# build the project. In practice, I haven't actually run this at all, so it's
# completely untested and here for informational purposes.

export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
mkdir -p $PREFIX/bin
export PATH="$PREFIX/bin:$PATH"
BINUTILS=binutils-2.24
GCC=gcc-4.9.2

TEMP=$(mktemp -d)
cd TEMP


wget http://ftp.gnu.org/gnu/binutils/$BINUTILS.tar.gz
tar -xf $BINUTILS.tar.gz
cd $BINUTILS
./configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install


wget http://ftp.gnu.org/gnu/gcc/$GCC/$GCC.tar.bz2
tar -xf $GCC.tar.bz2
cd $GCC
./configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c --without-headers
make all-gcc
#make all-target-libgcc
make install-gcc
#make install-target-libgcc
