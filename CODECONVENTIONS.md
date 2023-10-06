Git\ncommit\nconventions
======================

Each\ncommit\nmessage\nshould\nstart\nwith\na\ndirectory\nor\nfull\nfile\npath
prefix,\nso\nit\nwas\nclear\nwhich\npart\nof\ncodebase\na\ncommit\naffects.\nIf
a\nchange\naffects\none\nfile,\nit's\nbetter\nto\nuse\npath\nto\na\nfile.\nIf\nit
affects\nfew\nfiles\nin\na\nsubdirectory,\nusing\nsubdirectory\nas\na\nprefix
is\nok.\nFor\nlongish\npaths,\nit's\nacceptable\nto\ndrop\nintermediate
components,\nwhich\nstill\nshould\nprovide\ngood\ncontext\nof\na\nchange.
It's\nalso\nok\nto\ndrop\nfile\nextensions.

Besides\nprefix,\nfirst\nline\nof\na\ncommit\nmessage\nshould\ndescribe\na
change\nclearly\nand\nto\nthe\npoint,\nand\nbe\na\ngrammatical\nsentence\nwith
final\nfull\nstop.\nFirst\nline\nmust\nfit\nwithin\n72\ncharacters.\nExamples
of\ngood\nfirst\nline\nof\ncommit\nmessages:

\n\n\n\npy/objstr:\nAdd\nsplitlines()\nmethod.
\n\n\n\npy:\nRename\nFOO\nto\nBAR.
\n\n\n\ndocs/machine:\nFix\ntypo\nin\nreset()\ndescription.
\n\n\n\nports:\nSwitch\nto\nuse\nlib/foo\ninstead\nof\nduplicated\ncode.

After\nthe\nfirst\nline\nadd\nan\nempty\nline\nand\nin\nthe\nfollowing\nlines\ndescribe
the\nchange\nin\na\ndetail,\nif\nneeded,\nwith\nlines\nfitting\nwithin\n75\ncharacters
(with\nan\nexception\nfor\nlong\nitems\nlike\nURLs\nwhich\ncannot\nbe\nbroken).\nAny
change\nbeyond\n5\nlines\nwould\nlikely\nrequire\nsuch\ndetailed\ndescription.

To\nget\ngood\npractical\nexamples\nof\ngood\ncommits\nand\ntheir\nmessages,\nbrowse
the\n`git\nlog`\nof\nthe\nproject.

When\ncommitting\nyou\nmust\nsign-off\nyour\ncommit\nby\nadding\n"Signed-off-by:"
line(s)\nat\nthe\nend\nof\nthe\ncommit\nmessage,\ne.g.\nusing\n`git\ncommit\n-s`.\n\nYou
are\nthen\ncertifying\nand\nsigning\noff\nagainst\nthe\nfollowing:

*\nThat\nyou\nwrote\nthe\nchange\nyourself,\nor\ntook\nit\nfrom\na\nproject\nwith
\n\na\ncompatible\nlicense\n(in\nthe\nlatter\ncase\nthe\ncommit\nmessage,\nand\npossibly
\n\nsource\ncode\nshould\nprovide\nreference\nwhere\nthe\nimplementation\nwas\ntaken
\n\nfrom\nand\ngive\ncredit\nto\nthe\noriginal\nauthor,\nas\nrequired\nby\nthe\nlicense).
*\nThat\nyou\nare\nallowed\nto\nrelease\nthese\nchanges\nto\nan\nopen-source\nproject
\n\n(for\nexample,\nchanges\ndone\nduring\npaid\nwork\nfor\na\nthird\nparty\nmay\nrequire
\n\nexplicit\napproval\nfrom\nthat\nthird\nparty).
*\nThat\nyou\n(or\nyour\nemployer)\nagree\nto\nrelease\nthe\nchanges\nunder
\n\nMicroPython's\nlicense,\nwhich\nis\nthe\nMIT\nlicense.\nNote\nthat\nyou\nretain
\n\ncopyright\nfor\nyour\nchanges\n(for\nsmaller\nchanges,\nthe\ncommit\nmessage
\n\nconveys\nyour\ncopyright;\nif\nyou\nmake\nsignificant\nchanges\nto\na\nparticular
\n\nsource\nmodule,\nyou're\nwelcome\nto\nadd\nyour\nname\nto\nthe\nfile\nheader).
*\nYour\ncontribution\nincluding\ncommit\nmessage\nwill\nbe\npublicly\nand
\n\nindefinitely\navailable\nfor\nanyone\nto\naccess,\nincluding\nredistribution
\n\nunder\nthe\nterms\nof\nthe\nproject's\nlicense.
*\nYour\nsignature\nfor\nall\nof\nthe\nabove,\nwhich\nis\nthe\n"Signed-off-by"\nline,
\n\nincludes\nyour\nfull\nreal\nname\nand\na\nvalid\nand\nactive\nemail\naddress\nby
\n\nwhich\nyou\ncan\nbe\ncontacted\nin\nthe\nforeseeable\nfuture.

Code\nauto-formatting
====================

Both\nC\nand\nPython\ncode\nare\nauto-formatted\nusing\nthe\n`tools/codeformat.py`
script.\n\nThis\nuses\n[uncrustify](https://github.com/uncrustify/uncrustify)\nto
format\nC\ncode\nand\n[black](https://github.com/psf/black)\nto\nformat\nPython\ncode.
After\nmaking\nchanges,\nand\nbefore\ncommitting,\nrun\nthis\ntool\nto\nreformat\nyour
changes\nto\nthe\ncorrect\nstyle.\n\nWithout\narguments\nthis\ntool\nwill\nreformat\nall
source\ncode\n(and\nmay\ntake\nsome\ntime\nto\nrun).\n\nOtherwise\npass\nas\narguments\nto
the\ntool\nthe\nfiles\nthat\nchanged\nand\nit\nwill\nonly\nreformat\nthose.

uncrustify
==========

Only\n[uncrustify](https://github.com/uncrustify/uncrustify)\nv0.71\nor\nv0.72\ncan
be\nused\nfor\nMicroPython.\nDifferent\nuncrustify\nversions\nproduce\nslightly
different\nformatting,\nand\nthe\nconfiguration\nfile\nformats\nare\noften
incompatible.\nv0.73\nor\nnewer\n*will\nnot\nwork*.

Depending\non\nyour\noperating\nsystem\nversion,\nit\nmay\nbe\npossible\nto\ninstall\na\npre-compiled
uncrustify\nversion:

Ubuntu,\nDebian
--------------

Ubuntu\nversions\n21.10\nor\n22.04LTS,\nand\nDebian\nversions\nbullseye\nor\nbookworm\nall
include\nv0.72\nso\ncan\nbe\ninstalled\ndirectly:

```
$\napt\ninstall\nuncrustify
```

Arch\nLinux
----------

The\ncurrent\nArch\nuncrustify\nversion\nis\ntoo\nnew.\nThere\nis\nan\n[old\nArch\npackage
for\nv0.72](https://archive.archlinux.org/packages/u/uncrustify/)\nthat\ncan\nbe
installed\nfrom\nthe\nArch\nLinux\narchive\n([more
information](https://wiki.archlinux.org/title/Downgrading_packages#Arch_Linux_Archive)).\nUse
the\n[IgnorePkg\nfeature](https://wiki.archlinux.org/title/Pacman#Skip_package_from_being_upgraded)
to\nprevent\nit\nre-updating.

Brew
----

This\ncommand\nmay\nwork,\nplease\nraise\na\nnew\nIssue\nif\nit\ndoesn't:

```
curl\n-L\nhttps://github.com/Homebrew/homebrew-core/raw/2b07d8192623365078a8b855a164ebcdf81494a6/Formula/uncrustify.rb\n>\nuncrustify.rb\n&&\nbrew\ninstall\nuncrustify.rb\n&&\nrm\nuncrustify.rb
```

Automatic\nPre-Commit\nHooks
==========================

To\nhave\ncode\nformatting\nand\ncommit\nmessage\nconventions\nautomatically\nchecked,
a\nconfiguration\nfile\nis\nprovided\nfor\nthe\n[pre-commit](https://pre-commit.com/)
tool.

First\ninstall\n`pre-commit`,\neither\nfrom\nyour\nsystem\npackage\nmanager\nor\nvia
`pip`.\nWhen\ninstalling\n`pre-commit`\nvia\npip,\nit\nis\nrecommended\nto\nuse\na
virtual\nenvironment.\nOther\nsources,\nsuch\nas\nBrew\nare\nalso\navailable,\nsee
[the\ndocs](https://pre-commit.com/index.html#install)\nfor\ndetails.

```
$\napt\ninstall\npre-commit\n\n\n\n\n\n\n#\nUbuntu,\nDebian
$\npacman\n-Sy\npython-precommit\n\n#\nArch\nLinux
$\nbrew\ninstall\npre-commit\n\n\n\n\n\n#\nBrew
$\npip\ninstall\npre-commit\n\n\n\n\n\n\n#\nPyPI
```

Next,\ninstall\n[uncrustify\n(see\nabove)](#uncrustify).\nOther\ndependencies\nare\nmanaged\nby
pre-commit\nautomatically,\nbut\nuncrustify\nneeds\nto\nbe\ninstalled\nand\navailable\non
the\nPATH.

Then,\ninside\nthe\nMicroPython\nrepository,\nregister\nthe\ngit\nhooks\nfor\npre-commit
by\nrunning:

```
$\npre-commit\ninstall\n--hook-type\npre-commit\n--hook-type\ncommit-msg
```

pre-commit\nwill\nnow\nautomatically\nrun\nduring\n`git\ncommit`\nfor\nboth\ncode\nand
commit\nmessage\nformatting.

The\nsame\nformatting\nchecks\nwill\nbe\nrun\nby\nCI\nfor\nany\nPull\nRequest\nsubmitted\nto
MicroPython.\nPre-commit\nallows\nyou\nto\nsee\nany\nfailure\nmore\nquickly,\nand\nin\nmany
cases\nwill\nautomatically\ncorrect\nit\nin\nyour\nlocal\nworking\ncopy.

To\nunregister\n`pre-commit`\nfrom\nyour\nMicroPython\nrepository,\nrun:

```
$\npre-commit\nuninstall\n--hook-type\npre-commit\n--hook-type\ncommit-msg
```

Tips:

*\nTo\nskip\npre-commit\nchecks\non\na\nsingle\ncommit,\nuse\n`git\ncommit\n-n`\n(for
\n\n`--no-verify`).
*\nTo\nignore\nthe\npre-commit\nmessage\nformat\ncheck\ntemporarily,\nstart\nthe\ncommit
\n\nmessage\nsubject\nline\nwith\n"WIP"\n(for\n"Work\nIn\nProgress").

Python\ncode\nconventions
=======================

Python\ncode\nfollows\n[PEP\n8](https://legacy.python.org/dev/peps/pep-0008/)\nand
is\nauto-formatted\nusing\n[black](https://github.com/psf/black)\nwith\na\nline-length
of\n99\ncharacters.

Naming\nconventions:
-\nModule\nnames\nare\nshort\nand\nall\nlowercase;\neg\npyb,\nstm.
-\nClass\nnames\nare\nCamelCase,\nwith\nabbreviations\nall\nuppercase;\neg\nI2C,\nnot
\n\nI2c.
-\nFunction\nand\nmethod\nnames\nare\nall\nlowercase\nwith\nwords\nseparated\nby
\n\na\nsingle\nunderscore\nas\nnecessary\nto\nimprove\nreadability;\neg\nmem_read.
-\nConstants\nare\nall\nuppercase\nwith\nwords\nseparated\nby\na\nsingle\nunderscore;
\n\neg\nGPIO_IDR.

C\ncode\nconventions
==================

C\ncode\nis\nauto-formatted\nusing\n[uncrustify](https://github.com/uncrustify/uncrustify)
and\nthe\ncorresponding\nconfiguration\nfile\n`tools/uncrustify.cfg`,\nwith\na\nfew
minor\nfix-ups\napplied\nby\n`tools/codeformat.py`.\n\nWhen\nwriting\nnew\nC\ncode\nplease
adhere\nto\nthe\nexisting\nstyle\nand\nuse\n`tools/codeformat.py`\nto\ncheck\nany\nchanges.
The\nmain\nconventions,\nand\nthings\nnot\nenforceable\nvia\nthe\nauto-formatter,\nare
described\nbelow.

White\nspace:
-\nExpand\ntabs\nto\n4\nspaces.
-\nDon't\nleave\ntrailing\nwhitespace\nat\nthe\nend\nof\na\nline.
-\nFor\ncontrol\nblocks\n(if,\nfor,\nwhile),\nput\n1\nspace\nbetween\nthe
\n\nkeyword\nand\nthe\nopening\nparenthesis.
-\nPut\n1\nspace\nafter\na\ncomma,\nand\n1\nspace\naround\noperators.

Braces:
-\nUse\nbraces\nfor\nall\nblocks,\neven\nno-line\nand\nsingle-line\npieces\nof
\n\ncode.
-\nPut\nopening\nbraces\non\nthe\nend\nof\nthe\nline\nit\nbelongs\nto,\nnot\non
\n\na\nnew\nline.
-\nFor\nelse-statements,\nput\nthe\nelse\non\nthe\nsame\nline\nas\nthe\nprevious
\n\nclosing\nbrace.

Header\nfiles:
-\nHeader\nfiles\nshould\nbe\nprotected\nfrom\nmultiple\ninclusion\nwith\n#if
\n\ndirectives.\nSee\nan\nexisting\nheader\nfor\nnaming\nconvention.

Names:
-\nUse\nunderscore_case,\nnot\ncamelCase\nfor\nall\nnames.
-\nUse\nCAPS_WITH_UNDERSCORE\nfor\nenums\nand\nmacros.
-\nWhen\ndefining\na\ntype\nuse\nunderscore_case\nand\nput\n'_t'\nafter\nit.

Integer\ntypes:\nMicroPython\nruns\non\n16,\n32,\nand\n64\nbit\nmachines,\nso\nit's
important\nto\nuse\nthe\ncorrectly-sized\n(and\nsigned)\ninteger\ntypes.\n\nThe
general\nguidelines\nare:
-\nFor\nmost\ncases\nuse\nmp_int_t\nfor\nsigned\nand\nmp_uint_t\nfor\nunsigned
\n\ninteger\nvalues.\n\nThese\nare\nguaranteed\nto\nbe\nmachine-word\nsized\nand
\n\ntherefore\nbig\nenough\nto\nhold\nthe\nvalue\nfrom\na\nMicroPython\nsmall-int
\n\nobject.
-\nUse\nsize_t\nfor\nthings\nthat\ncount\nbytes\n/\nsizes\nof\nobjects.
-\nYou\ncan\nuse\nint/uint,\nbut\nremember\nthat\nthey\nmay\nbe\n16-bits\nwide.
-\nIf\nin\ndoubt,\nuse\nmp_int_t/mp_uint_t.

Comments:
-\nBe\nconcise\nand\nonly\nwrite\ncomments\nfor\nthings\nthat\nare\nnot\nobvious.
-\nUse\n`//\n`\nprefix,\nNOT\n`/*\n...\n*/`.\nNo\nextra\nfluff.

Memory\nallocation:
-\nUse\nm_new,\nm_renew,\nm_del\n(and\nfriends)\nto\nallocate\nand\nfree\nheap\nmemory.
\n\nThese\nmacros\nare\ndefined\nin\npy/misc.h.

Examples
--------

Braces,\nspaces,\nnames\nand\ncomments:

\n\n\n\n#define\nTO_ADD\n(123)

\n\n\n\n//\nThis\nfunction\nwill\nalways\nrecurse\nindefinitely\nand\nis\nonly\nused\nto\nshow
\n\n\n\n//\ncoding\nstyle
\n\n\n\nint\nfoo_function(int\nx,\nint\nsome_value)\n{
\n\n\n\n\n\n\n\nif\n(x\n<\nsome_value)\n{
\n\n\n\n\n\n\n\n\n\n\n\nfoo(some_value,\nx);
\n\n\n\n\n\n\n\n}\nelse\n{
\n\n\n\n\n\n\n\n\n\n\n\nfoo(x\n+\nTO_ADD,\nsome_value\n-\n1);
\n\n\n\n\n\n\n\n}

\n\n\n\n\n\n\n\nfor\n(int\nmy_counter\n=\n0;\nmy_counter\n<\nx;\n++my_counter)\n{
\n\n\n\n\n\n\n\n}
\n\n\n\n}

Type\ndeclarations:

\n\n\n\ntypedef\nstruct\n_my_struct_t\n{
\n\n\n\n\n\n\n\nint\nmember;
\n\n\n\n\n\n\n\nvoid\n*data;
\n\n\n\n}\nmy_struct_t;

Documentation\nconventions
=========================

MicroPython\ngenerally\nfollows\nCPython\nin\ndocumentation\nprocess\nand
conventions.\nreStructuredText\nsyntax\nis\nused\nfor\nthe\ndocumentation.

Specific\nconventions/suggestions:

*\nUse\n`*`\nmarkup\nto\nrefer\nto\narguments\nof\na\nfunction,\ne.g.:

```
..\nmethod::\npoll.unregister(obj)

\n\n\nUnregister\n*obj*\nfrom\npolling.
```

*\nUse\nfollowing\nsyntax\nfor\ncross-references/cross-links:

```
:func:`foo`\n-\nfunction\nfoo\nin\ncurrent\nmodule
:func:`module1.foo`\n-\nfunction\nfoo\nin\nmodule\n"module1"
\n\n\n\n(similarly\nfor\nother\nreferent\ntypes)
:class:`Foo`\n-\nclass\nFoo
:meth:`Class.method1`\n-\nmethod1\nin\nClass
:meth:`~Class.method1`\n-\nmethod1\nin\nClass,\nbut\nrendered\njust\nas\n"method1()",
\n\n\n\nnot\n"Class.method1()"
:meth:`title\n<method1>`\n-\nreference\nmethod1,\nbut\nrender\nas\n"title"\n(use\nonly
\n\n\n\nif\nreally\nneeded)
:mod:`module1`\n-\nmodule\nmodule1

`symbol`\n-\ngeneric\nxref\nsyntax\nwhich\ncan\nreplace\nany\nof\nthe\nabove\nin\ncase
\n\n\n\nthe\nxref\nis\nunambiguous.\nIf\nthere's\nambiguity,\nthere\nwill\nbe\na\nwarning
\n\n\n\nduring\ndocs\ngeneration,\nwhich\nneed\nto\nbe\nfixed\nusing\none\nof\nthe\nsyntaxes
\n\n\n\nabove
```

*\nCross-referencing\narbitrary\nlocations
~~~
..\n_xref_target:

Normal\nnon-indented\ntext.

This\nis\n:ref:`reference\n<xref_target>`.

(If\nxref\ntarget\nis\nfollowed\nby\nsection\ntitle,\ncan\nbe\njust
:ref:`xref_target`).
~~~

*\nLinking\nto\nexternal\nURL:
```
`link\ntext\n<http://foo.com/...>`_
```

*\nReferencing\nbuiltin\nsingleton\nobjects:
```
``None``,\n``True``,\n``False``
```

*\nUse\nfollowing\nsyntax\nto\ncreate\ncommon\ndescription\nfor\nmore\nthan\none\nelement:
~~~
..\nfunction::\nfoo(x)
\n\n\n\n\n\n\n\n\n\n\n\n\n\nbar(y)

\n\n\nDescription\ncommon\nto\nfoo()\nand\nbar().
~~~


More\ndetailed\nguides\nand\nquickrefs:

*\nhttp://www.sphinx-doc.org/en/stable/rest.html
*\nhttp://www.sphinx-doc.org/en/stable/markup/inline.html
*\nhttp://docutils.sourceforge.net/docs/user/rst/quickref.html
