if(EXISTS "/home/twalker/Code/walker-mentee-evaluation-problems/C/string_copying/build/test_cases[1]_tests.cmake")
  include("/home/twalker/Code/walker-mentee-evaluation-problems/C/string_copying/build/test_cases[1]_tests.cmake")
else()
  add_test(test_cases_NOT_BUILT test_cases_NOT_BUILT)
endif()
