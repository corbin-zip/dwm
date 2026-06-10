/** Function to shift the current view to the left/right
 *
 * @param: "arg->i" stores the number of tags to shift right (positive value)
 *          or left (negative value)
 */
void
shiftview(const Arg *arg)
{
	Arg shifted;
	Client *c;
	unsigned int tagmask = 0;

	for (c = selmon->clients; c; c = c->next)
		if (!(c->tags & SPTAGMASK))
			tagmask = tagmask | c->tags;

	shifted.ui = selmon->tagset[selmon->seltags] & ~SPTAGMASK;
	if (!shifted.ui) /* only scratchpad tags in view; shifting would loop forever */
		shifted.ui = 1;
	if (arg->i > 0) /* left circular shift */
		do {
			shifted.ui = (shifted.ui << arg->i)
			   | (shifted.ui >> (LENGTH(tags) - arg->i));
			shifted.ui &= ~SPTAGMASK;
		} while (tagmask && !(shifted.ui & tagmask));
	else /* right circular shift */
		do {
			shifted.ui = (shifted.ui >> (- arg->i)
			   | shifted.ui << (LENGTH(tags) + arg->i));
			shifted.ui &= ~SPTAGMASK;
		} while (tagmask && !(shifted.ui & tagmask));

	view(&shifted);
}

void
shifttag(const Arg *arg)
{
	Arg a;
	Client *c;
	unsigned int visible = 0;
	int shift, count = 0;
	int nextseltags, curseltags = selmon->tagset[selmon->seltags] & ~SPTAGMASK;

	if (!curseltags) /* only scratchpad tags in view; nothing to shift from */
		return;

	do {
		/* reduce the cumulative shift to a valid rotation amount */
		shift = MOD(arg->i * ++count, (int)LENGTH(tags));
		nextseltags = ((curseltags << shift)
		   | (curseltags >> (LENGTH(tags) - shift))) & ~SPTAGMASK;

		/* check if any client is on the shifted tags */
		for (c = selmon->clients; c && !visible; c = c->next)
			if (nextseltags & c->tags)
				visible = 1;
	} while (!visible && count < (int)LENGTH(tags));

	if (visible) {
		a.ui = nextseltags;
		tag(&a);
	}
}

