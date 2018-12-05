### How to Write Go Code 

every project has a separate workspace and workspaces are closely tied to version control repositories

#### Workspace 

A workspace is a directory hierarchy with two directories at its root:

- `src` contains Go source files, and
- `bin` contains executable commands.

The `go` tool builds and installs binaries to the `bin` directory.

The `src` **subdirectory typically contains multiple version control repositories** (such as for Git or Mercurial) that track the development of one or more source packages.

