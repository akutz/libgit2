	return (digits > 0) ? 0 : -1;
		const char *scan = bufs[0].ptr;
		if (*scan != '@')
			return -1;

		if (read_next_int(&scan, &range.old_start) < 0)
			return -1;
		if (*scan == ',' && read_next_int(&scan, &range.old_lines) < 0)
			return -1;

		if (read_next_int(&scan, &range.new_start) < 0)
			return -1;
		if (*scan == ',' && read_next_int(&scan, &range.new_lines) < 0)
			return -1;

		if (range.old_start < 0 || range.new_start < 0)
			return -1;

		return info->hunk_cb(
			info->cb_data, info->delta, &range, bufs[0].ptr, bufs[0].size);

	if ((len == 2 || len == 3) && info->line_cb) {
		if (info->line_cb(
			info->cb_data, info->delta, origin, bufs[1].ptr, bufs[1].size) < 0)
			return -1;
		if (len == 3) {
			return info->line_cb(
	return 0;
static int update_file_is_binary_by_attr(git_repository *repo, git_diff_file *file)
	if (git_attr_get(repo, file->path, "diff", &value) < 0)
		return -1;

	if (GIT_ATTR_FALSE(value))
	else if (GIT_ATTR_TRUE(value))

	return 0;
static void update_delta_is_binary(git_diff_delta *delta)
	int error = 0, mirror_new;
		return 0;
		return 0;
	if (update_file_is_binary_by_attr(diff->repo, &delta->old) < 0)
		return -1;
		error = update_file_is_binary_by_attr(diff->repo, &delta->new);
	update_delta_is_binary(delta);
	update_delta_is_binary(delta);
	return 0;
		return 0;
	if (git_blob_lookup(blob, repo, oid) < 0)
		return -1;
	map->data = (void *)git_blob_rawcontent(*blob);
	map->len  = git_blob_rawsize(*blob);
	return 0;
	int error = 0;
	git_buf path = GIT_BUF_INIT;

	if (git_buf_joinpath(&path, git_repository_workdir(repo), file->path) < 0)
		return -1;
		ssize_t read_len;

		GITERR_CHECK_ALLOC(map->data);

		read_len = p_readlink(path.ptr, map->data, (size_t)file->size + 1);
		if (read_len != (ssize_t)file->size) {
			giterr_set(GITERR_OS, "Failed to read symlink '%s'", file->path);
			error = -1;
		} else
			map->len = read_len;
		error = git_futils_mmap_ro_file(map, path.ptr);
	git_buf_free(&path);
	int error = 0;
		if (delta->status == GIT_DELTA_UNMODIFIED &&
			(diff->opts.flags & GIT_DIFF_INCLUDE_UNMODIFIED) == 0)
		if ((error = file_is_binary_by_attr(diff, delta)) < 0)
			if (error < 0)
			if (error < 0)
				if (error < 0)
					if ((diff->opts.flags & GIT_DIFF_INCLUDE_UNMODIFIED) == 0)
						goto cleanup;
			if (error < 0)
			if (error < 0)
		if (error < 0)
		return 0;
	if (git_buf_oom(pi->buf))
		return -1;
	if (git_buf_oom(pi->buf))
		return -1;

	return 0;
	int result;
	if (!oldpfx)
		oldpfx = DIFF_SRC_PREFIX_DEFAULT;

	if (!newpfx)
		newpfx = DIFF_DST_PREFIX_DEFAULT;


	if (print_oid_range(pi, delta) < 0)
		return -1;
		newpfx = "";
		newpath = "/dev/null";
	if (git_buf_oom(pi->buf))
		return -1;

    result = pi->print_cb(pi->cb_data, GIT_DIFF_LINE_FILE_HDR, pi->buf->ptr);
    if (result < 0)
        return result;
    if (delta->binary != 1)
        return 0;
	if (git_buf_oom(pi->buf))
		return -1;
	if (git_buf_printf(pi->buf, "%.*s", (int)header_len, header) < 0)
		return -1;
	return pi->print_cb(pi->cb_data, GIT_DIFF_LINE_HUNK_HDR, pi->buf->ptr);
	if (git_buf_oom(pi->buf))
		return -1;
	return 0;