clens
========

clens is a convenience library to aid in porting code from OpenBSD to
different operating systems. Operating systems traditionally have
different enough APIs that porting code is painful and can litter pretty
code with ugly #ifdef goo. In order to keep code readable and
drastically reduce the number of #ifdefs needed, clens brings other APIs
or missing functions into specific OS "focus". All our code is primarily
developed on OpenBSD and clens brings OpenBSD specific calls to other
operating systems. As a result, clens is not required when running
OpenBSD code.

## License

clens is licensed under the liberal ISC License.
