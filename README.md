# word-compressor

word-compressor is a Unix text compressor written in C that uses a switch algorithm to change the most frequent words in order to reduce the file size up to 50% of it's original size.

### License

This project is licensed under the MIT License.

### Install ###

```sh
wget "https://github.com/JuliaStrings/utf8proc/archive/v2.2.0.tar.gz" -O utf8proc-2.2.0.tar.gz
tar -zxvf utf8proc-2.2.0.tar.gz
cd utf8proc-2.2.0
make
make install
ldconfig
cd ~

git clone "https://github.com/bipbop/word-compressor.git"
cd word-compressor
make
make install
cd ~
ldconfig

git clone "https://github.com/bipbop/php-word-compressor.git"
cd php-word-compressor
phpize
./configure
make
make install
echo "extension=wordcompression.so" | tee -a /opt/php-7.2/lib/php.ini
