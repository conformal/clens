%define name		clens
%define version		0.4.0
%define release		1

Name: 		%{name}
Summary: 	Convenience library to aid in porting OpenBSD code to other OSes
Version: 	%{version}
Release: 	%{release}
License: 	ISC
Group: 		System Environment/Libraries
URL:		http://opensource.conformal.com/wiki/clens
Source: 	%{name}-%{version}.tar.gz
Buildroot:	%{_tmppath}/%{name}-%{version}-buildroot
Prefix: 	/usr
Requires:	libbsd

%description
clens is a convenience library to aid in porting code from OpenBSD to different
operating systems. Operating systems traditionally have different enough APIs
that porting code is painful and can litter pretty code with ugly #ifdef goo.
In order to keep code readable and drastically reduce the number of #ifdefs
needed, clens brings other APIs or missing functions into specific OS "focus".

%prep
%setup -q

%build
make

%install
make install DESTDIR=$RPM_BUILD_ROOT LOCALBASE=/usr


%package devel
Summary:	Libraries and header files to develop applications using clens
Group:		Development/Libraries
Requires:	libbsd-devel

%description devel
This package contains the libraries, include files, and documentation to
develop applications with clens.

%files devel
%defattr(-,root,root)
/usr/include/clens
/usr/lib/libclens.a

%changelog
* Fri Jan 06 2012 - davec 0.4.0-1
- Add glob with BSD extensions for platforms that need it
* Thu Oct 27 2011 - davec 0.3.0-1
- Add strnunvis for platforms that need it
- Properly define __dead and __packed attributes for gcc compiler
- Misc cleanup and build versioning
* Wed Aug 15 2011 - davec 0.2.0-1
- Add strtonum for platforms that need it
- Add RB_FOREACH_SAFE and RB_FOREACH_REVERSE_SAFE for platforms that need it
* Tue Jul 26 2011 - davec 0.1.0-1
- Add prototype for scan_scaled
- Define timespeccmp for platforms that need it
* Tue Jul 03 2011 - davec 0.0.5-1
- Create
