import { Button } from "@chakra-ui/button";
import { RadioGroup } from "@headlessui/react";
import React, { useEffect, useState } from "react";
import { useGame } from "../../contexts/GameContext";
import { useQuestion } from "../../contexts/QuestionContext";
import { createMessage } from "../../lib/createMessage";

export default function MultipleChoice() {
	const [selected, setSelected] = useState("");
	const { answerChoices, submitQuestion, questionIdx } = useQuestion();
	const [submitted, setSubmitted] = useState(false);
	const { sendWs } = useGame();

	const handleSubmit = (answer: string | number) => {
		submitQuestion();
		setSubmitted(true);
		sendWs(
			createMessage("question-submitted", {
				answer,
				currentQuestion: questionIdx,
			})
		);
	};

	useEffect(() => {
		// sets submission status to false on a new question
		setSubmitted(false);
	}, [questionIdx]);

	return (
		<div className="w-full my-5 py-3">
			<div className="w-full mx-auto">
				<RadioGroup value={selected} onChange={setSelected}>
					<RadioGroup.Label className="sr-only">Server size</RadioGroup.Label>
					<div className="space-y-2">
						{answerChoices.map((plan, i) => (
							<RadioGroup.Option
								key={plan}
								value={i}
								className={({ active, checked }) =>
									`${
										active
											? "ring-2 ring-offset-2 ring-offset-light-blue-300 ring-white ring-opacity-60"
											: ""
									}
                  ${
										checked
											? "bg-light-blue-900 text-gray-500 bg-opacity-75"
											: "bg-white"
									}
                    relative rounded-lg shadow-md px-5 py-5 cursor-pointer flex focus:outline-none`
								}
							>
								{({ checked }) => (
									<>
										<div className="flex items-center justify-between w-full">
											<div className="flex items-center">
												<div className="prose-sm">
													<RadioGroup.Label
														as="p"
														className={`font-medium  ${
															checked ? "text-gray-500" : "text-gray-900"
														}`}
													>
														{plan}
													</RadioGroup.Label>
												</div>
											</div>
											{checked && (
												<div className="flex-shrink-0 text-black">
													<CheckIcon className="w-6 h-6" />
												</div>
											)}
										</div>
									</>
								)}
							</RadioGroup.Option>
						))}
					</div>
				</RadioGroup>
			</div>
			<div className="py-4">
				<Button
					onClick={() => handleSubmit(selected)}
					isFullWidth
					colorScheme="facebook"
					disabled={submitted}
				>
					Submit
				</Button>
			</div>
		</div>
	);
}

const CheckIcon = (props) => {
	return (
		<svg viewBox="0 0 24 24" fill="none" {...props}>
			<circle cx={12} cy={12} r={12} fill="#808080" opacity="0.2" />
			<path
				d="M7 13l3 3 7-7"
				stroke="#808080"
				strokeWidth={1.5}
				strokeLinecap="round"
				strokeLinejoin="round"
			/>
		</svg>
	);
};
