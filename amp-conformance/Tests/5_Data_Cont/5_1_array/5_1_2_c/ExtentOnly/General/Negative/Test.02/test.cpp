// Copyright (c) Microsoft
// All rights reserved
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
// You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
// THIS CODE IS PROVIDED *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED,
// INCLUDING WITHOUT LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
// See the Apache Version 2.0 License for specific language governing permissions and limitations under the License.
/// <tags>P1</tags>
/// <summary>testing array with 0 rank.</summary>
//#Expects: Error: error C2338:.*(The _Rank of array_view should be greater than 0 )?

#include "./../../../../constructor.h"
#include <amptest_main.h>

runall_result test_main()
{
	Concurrency::extent<1> e(10);
    Concurrency::array<int, 0> foo{e};

	// We shouldn't compile
    return runall_fail;
}

