/*
 * This code is distributed under the terms of the GNU General Public License.
 * For more information, please refer to the LICENSE file in the root directory.
 * -------------------------------------------------
 * Copyright (C) 2025 Rodrigo R.
 * This program comes with ABSOLUTELY NO WARRANTY; for details type show w'.
 * This is free software, and you are welcome to redistribute it
 * under certain conditions; type show c' for details.
*/

#ifndef MUTEX_LIBRARY_H
#define MUTEX_LIBRARY_H

// ============= FLUENT LIB C =============
// mutex_t API
// ----------------------------------------
// Cross-platform mutex abstraction for thread synchronization.
// This library provides a simple way to create, lock, unlock,
// and destroy mutexes in a platform-independent manner.
// Internally, it uses CRITICAL_SECTION on Windows and pthread_mutex_t on POSIX systems.
// ----------------------------------------
// Features:
// - mutex_init:     Initialize a mutex.
// - mutex_lock:     Acquire the mutex lock (blocks if already locked).
// - mutex_unlock:   Release the mutex lock.
// - mutex_destroy:  Clean up mutex resources.
//
// Function Signatures:
// ----------------------------------------
// int mutex_init(mutex_t *m);
//     Example:
//         mutex_t m;
//         mutex_init(&m);
//
// void mutex_lock(mutex_t *m);
//     Example:
//         mutex_lock(&m);
//
// void mutex_unlock(mutex_t *m);
//     Example:
//         mutex_unlock(&m);
//
// void mutex_destroy(mutex_t *m);
//     Example:
//         mutex_destroy(&m);
//
// ----------------------------------------
// Initial revision: 2025-05-26
// ----------------------------------------
// Depends on: windows.h (Win32), pthread.h (POSIX)
// ----------------------------------------

#ifdef _WIN32
// Pending Windows implementation review
//#   include <windows.h>
#else
#   include <pthread.h>
#endif

// ============= FLUENT LIB C++ =============
#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @brief Cross-platform mutex abstraction.
 *
 * This struct provides a platform-independent mutex implementation,
 * using CRITICAL_SECTION on Windows and pthread_mutex_t on POSIX systems.
 */
typedef struct {
#ifdef _WIN32
// Pending Windows implementation review
//    CRITICAL_SECTION cs;   /**< Windows critical section */
#else
    pthread_mutex_t mutex; /**< POSIX mutex */
#endif
} mutex_t;

/**
 * @brief Initializes the mutex.
 *
 * @param m Pointer to the mutex_t structure to initialize.
 * @return 0 on success, or a non-zero error code on failure (POSIX only).
 */
static inline int mutex_init(mutex_t *m) {
#   ifdef _WIN32
    // Pending Windows implementation review
//    InitializeCriticalSection(&m->cs);
    return 0;
#   else
    return pthread_mutex_init(&m->mutex, NULL);
#   endif
}

/**
 * @brief Locks the mutex.
 *
 * Blocks if the mutex is already locked by another thread.
 *
 * @param m Pointer to the mutex_t structure to lock.
 */
static inline void mutex_lock(mutex_t *m) {
#   ifdef _WIN32
    // Pending Windows implementation review
//    EnterCriticalSection(&m->cs);
#   else
    pthread_mutex_lock(&m->mutex);
#   endif
}

/**
 * @brief Unlocks the mutex.
 *
 * Releases the lock held on the mutex.
 *
 * @param m Pointer to the mutex_t structure to unlock.
 */
static inline void mutex_unlock(mutex_t *m) {
#   ifdef _WIN32
    // Pending Windows implementation review
//    LeaveCriticalSection(&m->cs);
#   else
    pthread_mutex_unlock(&m->mutex);
#   endif
}

/**
 * @brief Destroys the mutex.
 *
 * Cleans up resources associated with the mutex.
 *
 * @param m Pointer to the mutex_t structure to destroy.
 */
static inline void mutex_destroy(mutex_t *m) {
#   ifdef _WIN32
    // Pending Windows implementation review
//    DeleteCriticalSection(&m->cs);
#   else
    pthread_mutex_destroy(&m->mutex);
#   endif
}

// ============= FLUENT LIB C++ =============
#if defined(__cplusplus)
}
#endif

#endif //MUTEX_LIBRARY_H