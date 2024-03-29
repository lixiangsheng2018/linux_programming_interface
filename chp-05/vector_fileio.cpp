#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _XOPEN_SOURCE

#include <assert.h>
#include <sys/uio.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include <sys/stat.h>

ssize_t writev(int fildes, const struct iovec *iov, int iovcnt)
{
	/* NOTE: we assume that we aren't opened with O_APPEND or anything
	 * crazy like that.  That just won't work.
	 */
	int i, bytes_written;
	struct iovec *vec;
	unsigned long long cnt = 0;
	ssize_t total_bytes_written = 0;

	/* validate input values */
	if (iovcnt < 0) {
		errno = EINVAL;
		return -1;
	}
	for (i = 0; i < iovcnt; i++) {
		vec = (struct iovec *)&iov[i];
		cnt += vec->iov_len;
		if (cnt > SSIZE_MAX) {
			errno = EINVAL;
			return -1;
		}
	}

	/* before starting, verify that the sum of lengths is not
	 * greater than the SSIZE_MAX
	 */

	for (i = 0; i < iovcnt; i++) {
		vec = (struct iovec *)&iov[i];
		bytes_written = write(fildes, vec->iov_base, vec->iov_len);
		if (bytes_written < 0) {
			return bytes_written;
		} else {
			total_bytes_written += bytes_written;
			if (bytes_written < vec->iov_len)
				return total_bytes_written;
		}
	}
	return total_bytes_written;
}


ssize_t readv(int fildes, const struct iovec *iov, int iovcnt)
{
	int i, bytes_read;
	struct iovec *vec;
	unsigned long long cnt = 0;
	ssize_t total_bytes_read = 0;

	if (iovcnt <= 0) {
		errno = EINVAL;
		return -1;
	}
	for (i = 0; i < iovcnt; i++) {
		vec = (struct iovec *)&iov[i];
		cnt += vec->iov_len;
		if (cnt > SSIZE_MAX) {
			errno = EINVAL;
			return -1;
		}
	}

	for (i = 0; i < iovcnt; i++) {
		vec = (struct iovec *)&iov[i];
		bytes_read = read(fildes, vec->iov_base, vec->iov_len);
		if (bytes_read < 0) {
			return bytes_read;
		} else {
			total_bytes_read += bytes_read;
			if (bytes_read < vec->iov_len)
				return total_bytes_read;
		}
	}

	return total_bytes_read;
}


#define NUMBER_VECS (100)
#define CHUNK_SIZE (16)

static struct iovec read_iovecs[NUMBER_VECS];
static struct iovec write_iovecs[NUMBER_VECS];

int main(int argc, char *argv[])
{
	int i;

	(void)argc;

	/* Create buffers (malloc) */
	for (i = 0; i < NUMBER_VECS; i++) {
		void * mem;

		mem = malloc(CHUNK_SIZE);
		memset(mem, 0, CHUNK_SIZE);
		read_iovecs[i].iov_base = mem;
		read_iovecs[i].iov_len = CHUNK_SIZE;

		mem = malloc(CHUNK_SIZE);
		memset(mem, i, CHUNK_SIZE);
		write_iovecs[i].iov_base = mem;
		write_iovecs[i].iov_len = CHUNK_SIZE;
	}

	/* Write the data to the file */
	int fd = open(argv[1], (O_WRONLY | O_CREAT), (S_IRUSR | S_IWUSR));
	ssize_t bytes_written = writev(fd, &write_iovecs[0], NUMBER_VECS);
	assert (bytes_written == (NUMBER_VECS * CHUNK_SIZE));
	close(fd);

	/* Read it back now */
	fd = open(argv[1], (O_RDONLY));
	ssize_t bytes_read = readv(fd, &read_iovecs[0], NUMBER_VECS);
	assert (bytes_read == (NUMBER_VECS * CHUNK_SIZE));

	/* Compare and assert equal */
	for (i = 0; i < NUMBER_VECS; i++) {
		assert(memcmp((void *)write_iovecs[i].iov_base,
					   (void *)read_iovecs[i].iov_base,
					   CHUNK_SIZE) == 0);
	}
	printf("Done... no assertion errors\n");

	return 0;
}
