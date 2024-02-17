# Minimal makefile for Sphinx documentation
#

# You can set these variables from the command line, and also
# from the environment for the first two.
SPHINXOPTS    ?=
SPHINXBUILD   ?= sphinx-build
SOURCEDIR     = .
BUILDDIR      = build_

# Put it first so that "make" without argument is like "make help".
help:
	@$(SPHINXBUILD) -M help "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

.PHONY: help Makefile

# Catch-all target: route all unknown targets to Sphinx using the new
# "make mode" option.  $(O) is meant as a shortcut for $(SPHINXOPTS).
%: Makefile
	@$(SPHINXBUILD) -M $@ "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

setup_latexpdf:
	pip install -r requirements.txt
	@echo
	@echo "==>  To allow *make latexpdf* install texlatex [take ~2min] with:"
	@echo
	@echo sudo apt-get install texlive-xetex latexmk texlive-latex-recommended \
		                       texlive-extra-utils texlive-sciences
	@echo
	@echo "==>  To have mermaid on pdf install mmdc https://github.com/mermaidjs/mermaid.cli#install-locally"
	@echo
	@echo npm install -g npm  # npm update
	@echo npm install -g @mermaid-js/mermaid-cli
	@echo mmdc --version

doc:
	@make html
	@make latexpdf
	@cp _build/latex/pricer.pdf ../.
