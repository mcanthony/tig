#define SIZEOF_REVGRAPH	19	/* Size of revision ancestry graphics. */
#define TIG_LS_REMOTE \
	"git ls-remote . 2>/dev/null"

#define TIG_DIFF_CMD \
	"git show --patch-with-stat --find-copies-harder -B -C %s"

#define TIG_LOG_CMD	\
	"git log --cc --stat -n100 %s"

#define TIG_MAIN_CMD \
	"git log --topo-order --stat --pretty=raw %s"

/* XXX: Needs to be defined to the empty string. */
#define TIG_HELP_CMD	""
#define TIG_PAGER_CMD	""

	REQ_(TOGGLE_LINENO,	"Toggle line numbers"), \
	REQ_(TOGGLE_REV_GRAPH,	"Toggle revision graph visualization"),
/*
 * Options
 */
static bool opt_rev_graph	= TRUE;
enum option_type {
	OPT_NONE,
	OPT_INT,
};

static bool
check_option(char *opt, char short_name, char *name, enum option_type type, ...)
{
	va_list args;
	char *value = "";
	int *number;

	if (opt[0] != '-')
		return FALSE;

	if (opt[1] == '-') {
		int namelen = strlen(name);

		opt += 2;

		if (strncmp(opt, name, namelen))
			return FALSE;

		if (opt[namelen] == '=')
			value = opt + namelen + 1;

	} else {
		if (!short_name || opt[1] != short_name)
			return FALSE;
		value = opt + 2;
	}

	va_start(args, type);
	if (type == OPT_INT) {
		number = va_arg(args, int *);
		if (isdigit(*value))
			*number = atoi(value);
	}
	va_end(args);

	return TRUE;
}

		if (check_option(opt, 'n', "line-number", OPT_INT, &opt_num_interval)) {
		if (check_option(opt, 'b', "tab-size", OPT_INT, &opt_tab_size)) {
			opt_tab_size = MIN(opt_tab_size, TABSIZE);
		if (check_option(opt, 'v', "version", OPT_NONE)) {
		if (check_option(opt, 'h', "help", OPT_NONE)) {
/*
 * Line-oriented content detection.
 */
static struct int_map color_map[] = {
#define COLOR_MAP(name) { #name, STRING_SIZE(#name), COLOR_##name }
	COLOR_MAP(DEFAULT),
	COLOR_MAP(BLACK),
	COLOR_MAP(BLUE),
	COLOR_MAP(CYAN),
	COLOR_MAP(GREEN),
	COLOR_MAP(MAGENTA),
	COLOR_MAP(RED),
	COLOR_MAP(WHITE),
	COLOR_MAP(YELLOW),
};

static struct int_map attr_map[] = {
#define ATTR_MAP(name) { #name, STRING_SIZE(#name), A_##name }
	ATTR_MAP(NORMAL),
	ATTR_MAP(BLINK),
	ATTR_MAP(BOLD),
	ATTR_MAP(DIM),
	ATTR_MAP(REVERSE),
	ATTR_MAP(STANDOUT),
	ATTR_MAP(UNDERLINE),
};

		unsigned int view_lines = view->offset + view->height;
				   ? MIN(view_lines, view->lines) * 100 / view->lines
	if (view == VIEW(REQ_VIEW_HELP)) {
		load_help_page();

	} else if ((reload || strcmp(view->vid, view->id)) &&
		   !begin_update(view)) {
	case REQ_TOGGLE_REV_GRAPH:
		opt_rev_graph = !opt_rev_graph;
		redraw_display();
		break;

	char id[41];			/* SHA1 ID. */
	char title[75];			/* First line of the commit message. */
	char author[75];		/* Author of the commit. */
	struct tm time;			/* Date from the author ident. */
	struct ref **refs;		/* Repository references. */
	chtype graph[SIZEOF_REVGRAPH];	/* Ancestry chain graphics. */
	size_t graph_size;		/* The width of the graph array. */
	if (opt_rev_graph && commit->graph_size) {
		size_t i;

		wmove(view->win, lineno, col);
		/* Using waddch() instead of waddnstr() ensures that
		 * they'll be rendered correctly for the cursor line. */
		for (i = 0; i < commit->graph_size; i++)
			waddch(view->win, commit->graph[i]);

		col += commit->graph_size + 1;
	}

	wmove(view->win, lineno, col);
		commit->graph[commit->graph_size++] = ACS_LTEE;
	{ 'g',		REQ_TOGGLE_REV_GRAPH},
		if (!string_format(buf, "%-25s %s", key, req_info[i].help))
	if (!strncmp(name, "refs/tags/", STRING_SIZE("refs/tags/"))) {
		/* Commits referenced by tags has "^{}" appended. */
		if (name[namelen - 1] != '}')
			return OK;

		namelen -= STRING_SIZE("refs/tags/");
		name	+= STRING_SIZE("refs/tags/");
		namelen -= STRING_SIZE("refs/heads/");
		name	+= STRING_SIZE("refs/heads/");
	ref->name = malloc(namelen + 1);
	strncpy(ref->name, name, namelen);
	ref->name[namelen] = 0;
	if (!strcmp(name, "i18n.commitencoding"))