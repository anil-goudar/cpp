#include "timer.h"
Timer::Timer() {
	m_beg_time = clock_t::now();
}
void Timer::reset() {
	m_beg_time = clock_t::now();
}
double Timer::elapsed() const {
	return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg_time).count();
}