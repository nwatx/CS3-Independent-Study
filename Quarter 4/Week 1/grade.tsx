import axios from "axios";
import { GetServerSideProps, GetServerSidePropsContext } from "next";
import { useRouter } from "next/router";
import { userInfo } from "os";
import GradingTable from "../../../components/Game/Grading/GradingTable";
import NavBarLayout from "../../../components/NavBarLayout";
import { db } from "../../../config";
import { useUser, UseUserInterface } from "../../../context/UserProvider";

export type Submission = {
	id: string;
	data: Map<String, String>;
};

export type GradeProps = {
	submissions: Submission[];
};

export default function grade({ submissions }: GradeProps) {

	const router = useRouter();


	return (
		<NavBarLayout>
			<div className="flex w-full justify-center p-10">
				<div className="flex w-1/2">
					<GradingTable submissions={submissions} />
				</div>
			</div>
		</NavBarLayout>
	);
}

export const getServerSideProps: GetServerSideProps = async (
	context: GetServerSidePropsContext
) => {
	const { id } = context.query;

	const submissions = [];

	await db.root
		.collection(`/games/${id}/submissions/`)
		.get()
		.then((qs) => {
			qs.forEach((doc) => {
				// console.log(doc.data());
				submissions.push({
					id: doc.id,
					data: doc.data(),
				});
			});
		});

	return {
		props: {
			submissions,
		},
	};
};
